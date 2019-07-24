import pandas as pd
from csv2txt import *
from csv2xlsx import *
from adjustCols import *
import win32com.client as win32

data = pd.read_csv('reporte.csv', sep = ';', encoding='latin-1')
# con resolucion y con estado aceptado es lo mismo
Aceptadas = data[data['Estado'] == 'Aceptado']
DeElectronicaAceptadas = Aceptadas[Aceptadas['Carrera'] == 'Ingeniería Electrónica']
nombresUnis = DeElectronicaAceptadas['Universidad externa con convenio'].drop_duplicates()

path = 'C:\\Users\\joa-m\\ideas\\Equivalencias'

names = {'NombresUnis': nombresUnis,'DeElectronicaAceptadas': DeElectronicaAceptadas}
for csvname, df in names.items():
    df.to_csv(path + '\\' + csvname + '.csv', sep = ';', encoding='latin-1')
    csv2xlsx(path, csvname, ';')
    excel = win32.gencache.EnsureDispatch('Excel.Application')
    wb = excel.Workbooks.Open(path + '\\' + csvname + '.xlsx')
    ws = wb.Worksheets("Sheet1")
    ws.Columns.AutoFit()
    wb.Save()
    excel.Application.Quit()




