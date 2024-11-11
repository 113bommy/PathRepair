from sys import stdin,stdout
def findops(l):
    ans=0
    count=1
    for i in range(1,len(l)):
        if l[i]>l[i-1]:
            count+=1
        else:
            ans=max(ans,count)
            count=1
    return len(l)-max(ans,count)
    

def main():
    for _ in range(int(stdin.readline())):
        stdin.readline()
        l=list(map(int,stdin.readline().split()))
        print(findops(sorted(range(len(l)),key=lambda x:l[x])))

main()