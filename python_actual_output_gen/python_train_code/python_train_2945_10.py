t = int(input())

def yes_or_no(health, void, light):
    if health <= light * 10:
        return True
    for i in range(void):
        health = (health // 2) + 10
    print(health, void, light)
    

    if 10 * light >= health:
        return True
    return False

for i in range(t):
    ui = list(map(int, input().split()))

    if yes_or_no(ui[0], ui[1], ui[2]):
        print("YES")
    else:
        print("NO")
    


