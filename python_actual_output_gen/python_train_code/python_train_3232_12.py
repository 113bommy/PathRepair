n_super, max_increase, max_op = list(map(int, input().strip().split()))

powers = list(map(int, input().strip().split()))
powers = sorted(powers)

curr_sum = sum(powers)
best_score = float("-inf")
for idx in range(n_super):
    n_remaining_hero = n_super - idx
    n_remaining_actions = max_op - idx
    if n_remaining_actions == 0:
        break
    this_score = curr_sum/n_remaining_hero + min(max_increase, n_remaining_actions/n_remaining_hero)

    if this_score > best_score:
        best_score = this_score

    curr_sum -= powers[idx]


print(best_score)
