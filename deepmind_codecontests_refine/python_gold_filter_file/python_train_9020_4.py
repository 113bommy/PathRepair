n= int(input());
a= list(map(int, input().split()));
#Словарь: пара число - максимальная длина последовательности, оканчивающаяся им.
d= dict();
for x in a:
    d[x]=d.get(x-1, 0)+1;
start=0;
finish=0;
result=0;
for key in d.keys():
    if d[key]>result:
        result=d[key];
        finish=key;
        start=key-d[key]+1;
print(result);
curr=start;
for i, x in enumerate(a):
    if curr==x:
        print(i+1, end=' ');
        curr+=1;
    
