import pandas as pd

xls = pd.ExcelFile('data1.xlsx')
ccgd = pd.read_excel(xls, 'CCGD')
snp = pd.read_excel(xls, 'SNP')

#print ccgd.shape     # (# row, # col)
#print ccgd.columns   # column names
#print snp[['scaffold name','Gene location']][:1]

snp_row_limit = 218710
ccgd_row_limit = 7788

snp_cnt = 0
ccgd_cnt = 0
for index, row_snd in snp.iterrows():
  snp_cnt = snp_cnt + 1
  found = 0

  if snp_cnt == snp_row_limit :
	break

  target_name = row_snd['scaffold name']
  target_value = row_snd['Gene location']

  print snp_cnt, " : ", target_value,

  for index, row in ccgd.iterrows():
    ccgd_cnt = ccgd_cnt + 1
    if ccgd_cnt == ccgd_row_limit :
	  break
  
    if row['Chromosome/scaffold name'] == target_name and  \
       row['Gene start (bp)'] < target_value and  \
       row['Gene end (bp)'] > target_value :
	  found = 1
	  print " : ", row['Gene stable ID'], row['Gene name']
	  row_snd['Gene stable ID'] = row['Gene stable ID']
	  row_snd['Gene name'] = row['Gene name']
	  
  if found == 0 :
	print " : N/A"
  	row_snd['Gene stable ID'] = "N/A"
  	row_snd['Gene name'] =  "N/A"


snp.to_excel('output.xlsx')


