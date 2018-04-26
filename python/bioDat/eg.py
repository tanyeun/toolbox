import pandas as pd
import pdb

xls = pd.ExcelFile('eg.xlsx')
std = pd.read_excel(xls, 'Standard')
race = pd.read_excel(xls, 'Race')

#print ccgd.shape     # (# row, # col)
#print ccgd.columns   # column names
#print snp[['scaffold name','Gene location']][:1]

#pdb.set_trace()

result=pd.merge(race,std,on='League')
result = result[(result.Distance >= result.Start)&(result.Distance < result.End)][["Name","League","Distance","Title"]]

result.to_excel('eg_out.xlsx')


