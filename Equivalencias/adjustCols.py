import openpyxl
from string import ascii_uppercase

def adjustCols(newFile):
    #newFile = "D:\Excel Files\abc.xlsx"
    wb = openpyxl.load_workbook(filename=newFile)
    worksheet = wb.active
    for col in worksheet.columns:
         max_length = 0
         column = col[0].column # Get the column name
    # Since Openpyxl 2.6, the column name is  ".column_letter" as .column became the column number (1-based)
         for cell in col:
             try: # Necessary to avoid error on empty cells
                 if len(str(cell.value)) > max_length:
                     max_length = len(cell.value)
             except:
                 pass
         adjusted_width = (max_length + 2) * 1.2
         worksheet.column_dimensions[column].width = adjusted_width
    return

