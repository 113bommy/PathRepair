x = int(input())
y = int(input())
z = int(input())

if x> z and y > z:
    print(z + 1)
elif x >= z and y < z or x< z and y >= z:
    print(min(x, y) + 1)
elif x + y == z :
    print("1")
elif x < z and y < z and x + y > z:
    print(x + y - z + 1) 
elif x + y > z and x == z and y == z:
    print("2")
    
#100, 160, 200  it starts from 40 and ends at 100 160 + 100 - 200 
#123 88 200 it starts from 77 and ends at 88 123 + 88 - 200 = 11 