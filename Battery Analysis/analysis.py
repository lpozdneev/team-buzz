import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


df_soc_ocv = pd.read_csv('soc_ocv_data.csv')  
soc_levels = ['100', '90', '80', '70', '60', '50', '40', '30', '20', '10', '0']
df_soc_ocv = df_soc_ocv.melt(id_vars=['Sample #'], value_vars=soc_levels, var_name='SOC', value_name='OCV')
df_soc_ocv["SOC"] = pd.to_numeric(df_soc_ocv["SOC"])
print(df_soc_ocv.dtypes)


dcir_levels = ['100', '90', '80', '70', '60', '50', '40', '30', '20', '10', '0']
df_dcir = pd.read_csv('dcir_data.csv')
df_dcir = df_dcir.melt(id_vars=['Sample #'], value_vars=dcir_levels, var_name='SOC', value_name='DCIR')
df_dcir["SOC"] = pd.to_numeric(df_dcir["SOC"])

print(df_dcir.dtypes)

df_cell_test_data = pd.merge(df_soc_ocv, df_dcir,  how='left', left_on=['Sample #','SOC'], right_on = ['Sample #','SOC'])

print(df_cell_test_data)

df_cell_test_data_grouped = df_cell_test_data.groupby(['Sample #'])

fig, (ax1, ax2) = plt.subplots(nrows=1, ncols=2, figsize=(12, 4))

ax1.set_title("OCV v. SOC")
ax1.set_xlim([100, 0])
ax1.set_xlabel('State of Charge (SOC)')
ax1.set_ylabel('Open Circuit Voltage (OCV)')



ax2.set_title("DCIR v. SOC")
ax2.set_xlim([100, 0])
ax2.set_xlabel('State of Charge (SOC)')
ax2.set_ylabel('DC Internal Resistance')





for key, item in df_cell_test_data_grouped:
    ax1.plot(item['SOC'].tolist(), item['OCV'].tolist())
    ax2.plot(item['SOC'].tolist(), item['DCIR'].tolist())
    # print(key)
    # print(item)

plt.tight_layout()
plt.show()
