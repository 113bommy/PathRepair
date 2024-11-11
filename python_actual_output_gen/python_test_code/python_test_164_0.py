def solve():
    u, v = map(int, input().split())
    if abs(u - v) % 2 != 0 or u > v: return -1
    elif u==v:
        return f"{1}\nu" if u!=0 else "0"
    else:
        x=(v-u)//2
        if(u&x):
            return f"3\n{u} {x} {x}"
        else:
            return f"2\n{u^x} {x}"

if __name__ == '__main__':
    print(solve())
