import math
import collections
import bisect
 
 
 
def cint() : return list(map(int, input().split())) 
def cstr() : return list(map(str, input().split(' '))) 
 
 
def solve():
    n = int(input())
    lst = cint()
 
    start = 0
    end = n-1
 
    ans = ''
    slen = 0
    prev = -1
    while start <= end:
        # print(start, end)
        if start==end:
            if lst[start] > prev:
                start+=1
                ans += 'L'
                slen += 1
                print(slen)
                print(ans)
                return
            else:
                start+=1
        
        if lst[start]==lst[end]:
            fcount = 0
            fstring =''
            findx = start
            bcount = 0
            bindx = end
            bstring = ''

            prevval = prev
            while findx <end:
                if lst[findx] > prevval:
                    prevval = lst[findx]
                    fcount+=1
                    fstring += 'L'
                    findx+=1
                else: break
                
            prevval = prev
            while bindx> start:
                if lst[bindx] > prevval:
                    prevval = lst[bindx]
                    bcount+=1
                    bstring += 'R'
                    bindx-=1
                else: break

            
            if fcount > bcount:
                slen += fcount
                ans += fstring
                print(slen)
                print(ans)
                return
            
            else:
                slen += bcount
                ans += bstring
                print(slen)
                print(ans)
                return
            

            




 
        if prev == -1:
            if lst[start] < lst[end]:
                prev = lst[start]
                start+=1
                ans += 'L'
            elif lst[start] > lst[end]:
                prev = lst[end]
                end-=1
                ans+='R'
            
            slen += 1
            
            
        
        else:
            if lst[start] < lst[end]:
                if lst[start] > prev:
                    prev = lst[start]
                    start+=1
                    ans+= 'L'
                    slen+=1
 
                elif lst[end] > prev:
                    prev = lst[end]
                    end-=1
                    ans+='R'
                    slen+=1
                
                else:
                    print(slen)
                    print(ans)
                    return
                    
 
 
            elif lst[start] > lst[end]:
                if lst[end] > prev:
                    prev = lst[end]
                    end-=1
                    ans+= 'R'
                    slen+=1
 
                elif lst[start] > prev:
                    prev = lst[start]
                    start+=1
                    ans+='L'
                    slen+=1
                
                else:
                    print(slen)
                    print(ans)
                    return
        
        
    print(slen)
    print(ans)
 
            
 
    
    
    
   
    
 
if __name__ == "__main__":
    # t = int(input())
    t = 1
    while t!=0:
        solve()
        t-=1