def get_list(L,i): return L[i] if len(L) > i else None
def print_key(key_name,val): print(key_name,"key = {0},".format(val), end=" ")
H = int(input())
hp = list(map(int,input().split()))
if H > 0:
    print_key("node 1:", hp[0])
    l = get_list(hp,1)
    r = get_list(hp,2)
    if l: print_key("left",l)
    if r: print_key("left",r)
    print("")
if H > 1:
    for i in range(2,H+1):
        print_key("node {0}:".format(i), hp[i-1])
        print_key("parent", hp[i//2-1])
        l = get_list(hp,i*2 -1)
        r = get_list(hp,i*2   )
        if l: print_key("left",l)
        if r: print_key("right",r)
        print("")