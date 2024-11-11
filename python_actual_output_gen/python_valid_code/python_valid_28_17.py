def read_file():
    with open("input.txt", "r") as f:
        return f.readlines()


def write_file(data):
    with open("output.txt", "w") as f:
        f.write(data)

n, a, b = map(int, input().split())
d = (a + b % n) % a
print(d if d != 0 else n)
