data = [int(input()) for i in range(6)]
print('Yay!' if data[-2] - data[0] < data[-1] else ':(')