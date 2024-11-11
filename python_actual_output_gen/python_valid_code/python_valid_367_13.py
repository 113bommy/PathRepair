l=[2,6,2,3,3,3,2,5,1,2]
n=int(input())
last=n%10
n=n//10
first=n%10
print(l[first]*l[last])