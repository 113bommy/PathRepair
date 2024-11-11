n=input()
a=list(map(lambda x: int(x),input().split()))
summ=0
for ii in a: summ+=ii
print(summ/(len(a)*100))
