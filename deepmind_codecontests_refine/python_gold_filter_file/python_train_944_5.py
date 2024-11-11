n = int(input())
ls1 = list()
ls2 = list()
ls1div = list()
ls2div = list()
count = 0
for i in range(0,n):
    ls1.append(input())
for i in range(0,n):
    ls2.append(input())
 
for i in range(1,5):
    ls1div.append([x[-1] for x in ls1 if len(x) == i])
    ls2div.append([x[-1] for x in ls2 if len(x) == i])
    count += abs(ls1div[i-1].count('S')-ls2div[i-1].count('S'))+abs(ls1div[i-1].count('M')-ls2div[i-1].count('M'))+abs(ls1div[i-1].count('L')-ls2div[i-1].count('L'))
    
print(int(count/2))