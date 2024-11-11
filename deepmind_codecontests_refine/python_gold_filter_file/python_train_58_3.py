def main():
    t, m = map(int, input().split())
    memory = [(0, m, 0)]
    next_id = 1

    for _ in range(t):
        cmd = list(input().split())
        if cmd[0] == 'defragment':
            new_mem = []
            rem_sz = 0
            start = 0
            for block in memory:
                if block[2] > 0:
                    new_mem.append((start, block[1] - block[0] + start, block[2]))
                    start = new_mem[-1][1]
                else:
                    rem_sz += block[1] - block[0]

            if rem_sz > 0:
                new_mem.append((start, start + rem_sz, 0))

            memory = new_mem
        elif cmd[0] == 'alloc':
            sz = int(cmd[1])

            ind = -1
            for i, block in enumerate(memory):
                if block[2] != 0:
                    continue

                if block[1] - block[0] >= sz:
                    ind = i
                    break

            if ind == -1:
                print('NULL')
                continue

            if memory[ind][1] - memory[ind][0] == sz:
                middle = [(memory[ind][0], memory[ind][0] + sz, next_id)]
            else:
                middle = [(memory[ind][0], memory[ind][0] + sz, next_id), (memory[ind][0] + sz, memory[ind][1], 0)]

            memory = memory[:ind] + middle + memory[ind + 1:]
            print(next_id)
            next_id += 1
        else:
            target = int(cmd[1])
            if target <= 0:
                print('ILLEGAL_ERASE_ARGUMENT')
                continue

            ind = -1
            for i, block in enumerate(memory):
                if block[2] == target:
                    ind = i
                    break

            if ind == -1:
                print('ILLEGAL_ERASE_ARGUMENT')
                continue

            memory[ind] = (memory[ind][0], memory[ind][1], 0)

            if ind > 0 and memory[ind - 1][2] == 0:
                memory[ind - 1] = (memory[ind - 1][0], memory[ind][1], 0)
                del memory[ind]
                ind -= 1

            if ind + 1 < len(memory) and memory[ind + 1][2] == 0:
                memory[ind] = (memory[ind][0], memory[ind + 1][1], 0)
                del memory[ind + 1]

        # print(memory)

main()
