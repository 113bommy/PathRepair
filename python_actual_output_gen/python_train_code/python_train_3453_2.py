n = int(input())

smil = input().split()

mmil = []

for i in range(len(smil)):
    mmil.append(int(smil[i]))

minh = min(mmil)
maxh = max(mmil)

mini = 0
maxi = len(mmil) -1 


for i in range(len(mmil)):
    if mmil[i] == minh and mini <= i:
        mini = i
    if mmil[i] == maxh and maxi >= i:
        maxi = i

if mini > maxi and (mini !=len(mmil)-1 and maxi != 0):
    print(len(mmil) - mini + maxi -1)
elif mini > maxi and (mini == len(mmil)-1 and maxi == 0):
    print(0)
elif mini < maxi:
    print(len(mmil) - mini + maxi - 2)
