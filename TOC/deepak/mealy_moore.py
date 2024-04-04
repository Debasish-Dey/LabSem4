t_table = {
    'A': {'0': ('B', 'a'), '1': ('C', 'a')},
    'B': {'0': ('B', 'b'), '1': ('C', 'a')},
    'C': {'0': ('B', 'a'), '1': ('C', 'b')}
}
states = {'A', 'B', 'C'}
alphabets = {'a', 'b'}
moore_states = {('A', 'a')}
for key in t_table:
    dictionary = t_table[key]
    for sub_key in dictionary:
        moore_states.add(dictionary[sub_key])
print(moore_states)
ans = {}
for tup in moore_states:
    ans[tup] = {}
print(ans)
for state in t_table:
    dictionary = t_table[state]
    for key in list(ans.keys()):
        if key[0] == state:
            for inp in dictionary:
                ans[key][inp] = dictionary[inp]
print(ans)