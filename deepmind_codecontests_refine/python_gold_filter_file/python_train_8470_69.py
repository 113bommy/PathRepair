k = int(input())
for i in range( k+1, 9999 ):
    a = i // 1000
    b = (i - a * 1000) // 100
    c = (i - a * 1000 - b * 100) // 10
    d = i % 10
    if ( a != b and a != c and a != d and b != c and b != d and c != d):
        print(i)
        break