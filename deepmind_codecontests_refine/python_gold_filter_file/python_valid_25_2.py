def sub_string ( s, t ):
    if t in s:
        return True
    if t[::-1] in s:
        return True
    return False

def poly (st):
    if st == st[::-1]:
        return True
    return False
    
def big_pol ( s, t ):
    if poly(t) and len(t) == 2*len(s)-1:
        if t[:len(t)//2+1] in s:
            #print('First')
            return True
        
    for i in range(1,len(t)):
        if poly(t[:-i]) and len(t[:-i])%2 != 0:
            if ( (t[-i:])[::-1] + (t[:-i])[:len(t[:-i])//2+1]   ) in s:
                #print((t[-i:])[::-1], "__", (t[:-i])[:len(t[:-i])//2+1], "  ", )
                return True
    return False


def little_pol (s, t):
    for i in range(1,len(t)):
        if poly(t[i:]) and len(t[i:])%2 != 0:
            if ( t[:i] + (t[i:])[:len(t[:-i])//2+1] ) in s:
                #print(t[:i],'==', (t[i:])[:len(t[:-i])//2+1])
                return True
    
    return False


def poly_mid (s,t):
    if poly(t) and len(t)%2 != 0:
        if t[:len(t)//2+1] in s:
            return True
    return False

def solve(s,t):
    if sub_string(s,t):
        print("YES")
        return None
    if big_pol(s,t):
        print("YES")
        return None
    if little_pol(s,t):
        print("YES")
        return None
    if poly_mid(s,t):
        print("YES")
        return None
        
    print("NO")
    return None


list_st = []
l = int(input())

for i in range(l):
    list_st.append(input())
    list_st.append(input())

for i in range(l):
    s = list_st[2*i]
    t = list_st[2*i+1]
    solve(s,t)
