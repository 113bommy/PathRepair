l=list(map(int,input().split()))
a=l[0]
b=l[1]+1
lis = str(list(range(a,b)))

sum=lis.count('0')*6+lis.count('1')*2+lis.count('2')*5+lis.count('3')*5+lis.count('4')*4+lis.count('5')*5+lis.count('6')*6+lis.count('6')*36+lis.count('8')*7+lis.count('9')*6
print(sum)
