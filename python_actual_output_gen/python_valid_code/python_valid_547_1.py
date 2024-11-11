t = int(input())

def check_min_entry(lst):
    min = 0
    extra = 0
    for i in lst:
        if min+extra<i:
            min = i-extra+1
        extra +=1
    return min

def check_main_entry(lst):
    min = 0
    extra = 0
    for i in lst:
        if min+extra<i[0]:
            min = i[0]-extra
        extra += i[1]
    return min

while t!=0:
    n = int(input())
    array = []
    min_entry = []
    for i in range(n):
        temp = list(map(int,input().split()))
        temp.pop(0)
        array.append(temp)
    
    for i in array:
        temp = [check_min_entry(i),len(i)]
        min_entry.append(temp)
    
    min_entry.sort(key= lambda x:x[0])
    print(check_main_entry(min_entry))
    t-=1
