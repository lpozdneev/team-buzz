import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns



xl = pd.ExcelFile("HyTech Racing Cell Validation Summary.xlsx")

df_soc_voltage_curve = pd.read_csv('soc_ocv_data.csv')  
print(df_soc_voltage_curve)
soc_levels = ['100', '90', '80', '70', '60', '50', '40', '30', '20', '10', '0']
df_soc_voltage_curve = df_soc_voltage_curve.melt(id_vars=['Sample #'], value_vars=soc_levels, var_name='SOC', value_name='OCV')
df_soc_voltage_curve["SOC"] = pd.to_numeric(df_soc_voltage_curve["SOC"])



