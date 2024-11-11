'''
a=input()
string=input()
n=int(input())
list1=[]
score=0

for i in range(n):
    list1.append((input()).split())


maX=int(input())

list2=[0]*len(string)
var = 0
while n>0:
    times = 0
    for i in range (len(string)):
        if string[i:i+len(list1[var][0])] == list1[var][0] and not maX in list2[i:i+len(list1[var][0])]:
            score += int(list1[var][1])
            for j in range(i, i+len(list1[var][0])):
                list2[j] += 1
            if i+len(list1[var][0]) == len(string):
                break
            if times == maX:
                break
    var += 1
    n -= 1

print(score)
'''

final=0
n= int(input())
list1=[]

for i in range(n):
    list1.append(int(input()))
list1.sort()
for i in range(n):
    final += list1[i] * list1[n-i-1]
print(final%10007)


    
