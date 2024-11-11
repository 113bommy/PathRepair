def Find(data,x):
    temp_data = [i-x for i in data]
    temp_data.sort()
    i = 0
    while i<len(temp_data) and temp_data[i]<0:
        i+=1
    if i == len(temp_data):
        return 0
    if i == 0:
        return len(temp_data)
    j = i-1
    present = temp_data[i]
    count = len(temp_data)-i
    while j>=0 and i<=len(data):
        if temp_data[j]+present>=0:
            present += temp_data[j]
            j-=1
            count+=1
        else:
            if i<len(temp_data):
                present += temp_data[i]
                i+=1
            else:
                i+=1    
    return count
def main():
    t = int(input())
    while t>0:
        t-=1
        n,x = map(int,input().split())
        data = list(map(int,input().split()))
        print(Find(data,x))
main()        