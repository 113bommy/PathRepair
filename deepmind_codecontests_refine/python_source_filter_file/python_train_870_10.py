n_wires = int(input())
wires = list(map(int, input().split(" ")))

n_shoots = int(input())
shoots = []
for it in range(n_shoots):
    shoot = tuple(map(int, input().split(" ")))
    shoots.append(shoot)

for idx, bird in shoots:
    if idx != 1:
        wires[idx - 2] += bird - 1
    if idx != n_wires:
        wires[idx] += wires[idx] - bird

    wires[idx - 1] = 0

for wire in wires:
    print(wire)
