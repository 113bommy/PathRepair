ans = 0


def check1(seq, i):
    if i == 0 or i == len(seq)-1:
        return False
    if seq[i] - seq[i-1] == 1 and seq[i] - seq[i+1] == 2:
        return True
    if seq[i] - seq[i+1] == 1 and seq[i] - seq[i-1] == 2:
        return True
    if seq[i] - seq[i-1] == 1 and seq[i] == seq[i+1]:
        return True
    if seq[i] - seq[i+1] == 1 and seq[i] == seq[i-1]:
        return True
    return False


def check2(seq, i):
    if i == 0 or i == len(seq)-1:
        return True
    if seq[i] - seq[i - 1] == 1 and seq[i + 1] - seq[i] >= 2:
        return True
    if seq[i] - seq[i + 1] == 1 and seq[i - 1] - seq[i] >= 2:
        return True
    if seq[i] - seq[i - 1] == 1 and seq[i] - seq[i + 1] >= 3:
        return True
    if seq[i] - seq[i + 1] == 1 and seq[i] - seq[i - 1] >= 3:
        return True
    if seq[i] - seq[i - 1] == 1 and seq[i] - seq[i + 1] == 1:
        return True
    if seq[i] - seq[i + 1] == 1 and seq[i] - seq[i - 1] == 1:
        return True
    return False


def check3(seq, i):
    if i == 0 or i == len(seq)-1:
        return False
    if seq[i] - seq[i - 1] == 1 and seq[i + 1] - seq[i] == 1:
        return True
    if seq[i] - seq[i + 1] == 1 and seq[i - 1] - seq[i] == 1:
        return True
    return False


def seq_to_str(seq):
    return ''.join([chr(s+ord('a')) for s in seq])


def make_move(seq):
    global ans
    candidates = []
    if len(seq) > 1:
        # Check first
        if seq[0] - seq[1] == 1:
            candidates.append(0)
        # Check others
        for i in range(1, len(seq) - 1):
            if seq[i]-seq[i+1] == 1 or seq[i]-seq[i-1] == 1:
                candidates.append(i)
        # Check last
        if seq[-1] - seq[-2] == 1:
            candidates.append(len(seq) - 1)
        #print(seq, candidates)

        if len(candidates) > 0:
            # Use priority
            priopity1 = list()
            priopity2 = list()
            priopity3 = list()
            for cand in candidates:
                if check1(seq, cand):
                    priopity1.append(cand)
                elif check2(seq, cand):
                    priopity2.append(cand)
                elif check3(seq, cand):
                    priopity3.append(cand)
            candidates_sorted = sorted(priopity1, key=lambda cand: seq[cand], reverse=True) + sorted(priopity2, key=lambda cand: seq[cand], reverse=True) + sorted(priopity3, key=lambda cand: seq[cand], reverse=True)
            to_del_index = candidates_sorted[0]
            new_seq = seq[0:to_del_index]+seq[to_del_index+1:]
            print(seq_to_str(new_seq), to_del_index, check1(seq, to_del_index), check2(seq, to_del_index), check3(seq, to_del_index))
            ans += 1
            make_move(new_seq)


_ = int(input())
seq = [ord(s) - ord('a') for s in input()]
make_move(seq)
print(ans)
