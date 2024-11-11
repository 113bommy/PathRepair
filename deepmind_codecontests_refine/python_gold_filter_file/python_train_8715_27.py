n = int(input())
mas = ['purple', 'green', 'blue', 'orange', 'red', 'yellow']
mas1 = ['purple', 'Power', 'green',  'Time', 'blue', 'Space', 'orange', 'Soul', 'red', 'Reality', 'yellow', 'Mind']
for i in range(n):
    mas.remove(input())
print(len(mas))
for i in mas:
    print(mas1[mas1.index(i) + 1])