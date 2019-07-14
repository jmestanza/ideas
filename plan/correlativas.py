import pandas as pd
data = pd.read_excel('1a3ro.xlsx', index_col=None, na_values=['NA'])
#data = pd.read_csv('1a3ro.csv')

new_data = []
for materia in data['Mat']:
    if materia.startswith('Año'):
        data.drop([materia])

#print(data['Mat'])

print(data)

#hola = data[:0].columns[0]
adios = []
#print(data['Año 1 - Cuatrimestre 2'])
#print(data['Año 1 - Cuatrimestre 2'])
#print(data[:0].columns[0])