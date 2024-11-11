if __name__=='__main__':
    n = (int)(input())
    k = (int)(n/4)
    st = 'abcd'*k
    m = n%4
    s = ['e','f','g']
    if n==1:
        st = 'a'
    elif n==2:
        st = 'ab'
    elif n==3:
        st = 'abc'
    else:
        for i in range(0,m):
            st+=s[i]
    print(st)