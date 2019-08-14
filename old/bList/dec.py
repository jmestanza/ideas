import pandas as pd

df = pd.read_excel (r'C:\Users\joa-m\ideas\listarda\list.xlsx')
itba_people = df[df['itba'] == 'No']
print(itba_people)