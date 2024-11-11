def main():
    a, b = map(int, input().split())
    x, y, z = map(int, input().split())
    result = 0
    
    a -= x*2 + y
    b -= y + z*3
    if a < 0:
        result -= a
    if b < 0:
        result -= b
    
    print(result)

main()