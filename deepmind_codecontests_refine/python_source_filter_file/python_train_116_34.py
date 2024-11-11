def solve():
    N = int(input())
    
    s = input()
    start = 0
    
    for i in range(1,N):
        if s[i] > s[start]:
            start = i
            continue
        
        if s[i] < s[start]:
            print ("YES")
            print (start+1, start+2)
            return
            
    print ("NO")    
    
if __name__ == "__main__":  
    solve()