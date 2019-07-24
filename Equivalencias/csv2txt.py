import csv

def csv2txt(filename,delimiter):
    csv_file = filename + '.csv'
    txt_file = filename + '.txt'
    with open(txt_file, "w") as my_output_file:
        with open(csv_file, "r") as my_input_file:
            [ my_output_file.write(delimiter.join(row)+'\n') for row in csv.reader(my_input_file, delimiter=';')]
        my_output_file.close()
    return

