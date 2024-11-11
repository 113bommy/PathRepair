n=int(input())
a=[int(x) for x in input().split()]
pro=n*(n-1)//2
dic={}
for item in a:
    if item not in dic:
        dic[item]=1
    else:
        dic[item]+=1
counter=0
for item in dic:
    if 0 in dic and dic[0]>=2:
        print('clsnb')
        break
    if dic[item]>2:
        print('cslnb')
        break
    elif dic[item]==2:
        if counter==1 or item-1 in dic:
            print('clsnb')
            break
        else:
            counter=1
else:
    if (sum(a)-pro)%2==1:
        print('sjfnb')
    else:
        print('cslnb')
