def isUnique(st): 
    if len(st) > 256: 
        return False
 
    char_set = [False] * 128
    for i in range(0, len(st)): 
        val = ord(st[i]) 
        if char_set[val]: 
            return False
  
        char_set[val] = True
  
    return True
def check(n):
    n=int(n)
    while(n <= 9012):
        n+=1
        st=str(n)
        flag=isUnique(st)
        if flag:
            return n
    
def main():
    # for i in range(1,n):
        # print(type(s))
    n=input()
    # print(type(n))
    ans=check(n)
    print(ans)
    # m, n = map(int, input().split())
main()