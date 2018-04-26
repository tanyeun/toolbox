import pandas as pd
import time

start_time = time.time()

xls = pd.ExcelFile('data1.xlsx')
print("--- %s seconds : create file handle ---" % (time.time() - start_time))

ccgd = pd.read_excel(xls, 'CCGD')
print("--- %s seconds : Read CCGD ---" % (time.time() - start_time))

snp = pd.read_excel(xls, 'SNP')
print("--- %s seconds : Read SNP ---" % (time.time() - start_time))


result = pd.merge(snp, ccgd, on='scaffold name')
print("--- %s seconds : Merge two tables ---" % (time.time() - start_time))

result = result[(result.location >= result.Start) & (result.location < result.End)][['scaffold name', 'location', 'Gene stable ID', 'Gene name']]

print("--- %s seconds : Filter result ---" % (time.time() - start_time))

result.to_excel('output.xlsx')


