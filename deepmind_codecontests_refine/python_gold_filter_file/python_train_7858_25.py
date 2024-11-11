a = int(input())
c = 0
mas1 = [ ]
mas = list(map(int,input().split()))
mas.append(0)
for i in range(a):
    if mas[i] <= mas[i+1]:
        c += 1
    else:
        mas1.append(c)
        c = 0
print(max(mas1)+1)