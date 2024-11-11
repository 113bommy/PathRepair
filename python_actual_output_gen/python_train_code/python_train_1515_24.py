fin = input()

w, h, k = map(int, fin.split(' '))

sum = 0

for i in range(k):
  sum += (w + h) * 2 - 4;
  w -= 2;
  h -= 2;

print(str(sum))