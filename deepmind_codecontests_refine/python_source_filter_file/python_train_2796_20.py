n,x = map(int,input().split())

def get_result():
    if x == 1 or x == 2*n-1:
        return []
    
    if N == 2:
        return [1,2,3]
    
    if x == 2:
        center = [3,2,1,4]
        others = list(range(5,2*n))
    elif x == 2*n-1:
        center = [2*n-3,2*n-2,2*n-1,2*n-4]
        others = list(range(1,2*n-4))
    else:
        center = [x+1,x,x-1,x+2]
        others = list(range(1,x-1)) + list(range(x+3,2*n))
    split_idx = 2*n-2
    result = others[:split_idx] + center + others[split_idx:]
    
    return result


res = get_result()
if len(res)==0:
    print("No")
else:
    print("Yes")
    for r in res:
        print(r)
        