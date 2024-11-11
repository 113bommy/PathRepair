

if __name__=='__main__':
    inp = input()
    arr = inp.split(" ")
    r = int(arr[0])
    h = int(arr[1])
    ans = 2*(h//r)
    d = h%r
    if d*2>=r:
        ans+=2
        if 2*d*(d+r) <= r*r:
            ans+=1
    else:
        ans+=1
    print(ans)
    
