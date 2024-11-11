foo = baz = 0
quz = 1
for bar in range(int(input())):
    foo += int(input())
    if foo * quz < baz * bar: break
    baz, quz = foo, bar
print(baz / quz)