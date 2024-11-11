# Solución al problema F, Misha and Changing Handles de Codeforces

from sys import stdin, stdout
values = []

n = 0
for line in stdin.readlines():

    if n == 0:
        n = int(line)
        continue
    else:
        values.append(line.strip().split(' '))

diccionario = {}
for value in values:
    if value[0] not in diccionario.values():
        diccionario[value[0]] = value[1]
    else:
        for key, value_1 in diccionario.items():
            if value_1 == value[0]:
                diccionario[key] = value[1]

output_list = [str(value[0]) + ' ' + str(value[1]) for value in list(diccionario.items())]


stdout.write(str(len(values)) + '\n')
stdout.writelines(["%s\n" % value for value in output_list])