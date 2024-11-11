from collections import defaultdict
n, A = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
location_dict = defaultdict(list)
tmp = [i for i in range(n) if c[i] == A]
if len(tmp) > 0:
    first_occurance = c.index(A)
    candidate = set(c[:first_occurance])
    if len(candidate) == 0:
        print(-1)
    else:
        candidate_occurance = dict()
        for i in candidate:
            candidate_occurance[i] = defaultdict(list)
        all_count = defaultdict(int)
        for i in range(n):
            all_count[c[i]] += 1
            location_dict[c[i]].append(i)
            if all_count[c[i]] < all_count[A] and c[i] in candidate:
                candidate.remove(c[i])
            if len(candidate) == 0:
                print(-1)
                break
        else:
            to_remove = set()
            for i in candidate: # each of the remaining candidate
                if len(location_dict[i]) < len(location_dict[A]):
                    to_remove.add(i)
                    continue
                for j in range(len(location_dict[A])):
                    if location_dict[i][j] > location_dict[A][j]:
                        to_remove.add(j)
                        break
            candidate = candidate.difference(to_remove)
            if len(candidate) == 0:
                print(-1)
            else:
                print(min(candidate))
else:
    print(c[0])
