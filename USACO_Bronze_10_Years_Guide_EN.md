# USACO Bronze 10-Year Practice Guide（近十年真题分类）

> Scope（范围）: the most recent 10 USACO seasons, **2016-2017 through 2025-2026**. The 2025-2026 US Open is a proctored invitational, so this guide includes the 2025-2026 First / Second / Third Bronze online contests only.

## 1. Bronze Skill Map（知识点地图）

USACO Bronze is mainly about **reading precision, state modeling, clean implementation, and complexity control**（读题建模、模拟实现、复杂度控制）, not advanced data structures.

| Skill | 中文标识 | Core idea | Exam focus |
|---|---|---|---|
| Simulation / Implementation | 模拟 / 实现 | Model state explicitly, then update it exactly as the statement says. | Check constraints first; write edge tests before submitting. |
| Ad Hoc / Casework | 分类讨论 | Look for invariants, small examples, and edge cases before coding. | Check constraints first; write edge tests before submitting. |
| Greedy | 贪心 | Sort or normalize the input, then justify why the local choice is safe. | Check constraints first; write edge tests before submitting. |
| Complete Search / Brute Force | 枚举 / 暴力 | Use constraints to choose enumeration depth; keep validation in a clean check function. | Check constraints first; write edge tests before submitting. |
| Sorting / Ordering | 排序 | After sorting, inspect neighbors, prefixes, suffixes, or endpoints. | Check constraints first; write edge tests before submitting. |
| Counting / Frequency | 计数 / 频率 | Use arrays, maps, sets, or contribution counting instead of repeated scans. | Check constraints first; write edge tests before submitting. |
| Prefix / Difference / Incremental Update | 前缀 / 差分 | Precompute reusable sums or maintain local contribution changes. | Check constraints first; write edge tests before submitting. |
| Grid / Geometry | 网格 / 几何 | Draw coordinates, standardize indexing, and watch inclusive/exclusive borders. | Check constraints first; write edge tests before submitting. |
| Graph-lite / Connectivity | 轻量图论 | Use adjacency, reachability, indegree/outdegree, or simple DFS/BFS when needed. | Check constraints first; write edge tests before submitting. |
| String Processing | 字符串 | Think in substrings, character counts, ordering, and pattern matching. | Check constraints first; write edge tests before submitting. |
| Math / Number Patterns | 数学规律 | Generate small cases, identify parity/modulo/divisibility patterns, then prove bounds. | Check constraints first; write edge tests before submitting. |

## 2. Practice Priority（刷题优先级）

### A. Simulation + Ad Hoc（模拟 + 分类讨论）

These are the highest-frequency Bronze patterns. Target: solve P1/P2 in 30-45 minutes and get stable progress on P3.

- Representative problems: Word Processor, Race, Stuck in a Rut, Air Cownditioning, Candy Cane Feast, Roundabout Rounding, Chip Exchange.
- Exam focus（考试要点）: define state variables, update them exactly, and look for local contribution or invariants.

### B. Counting / Sets / Maps / Strings（计数 / 集合 / 字符串）

- Representative problems: Guess the Animal, Where Am I?, Cow Gymnastics, Herdle, FEB, Majority Opinion, It's Mooin' Time series.
- Exam focus（考试要点）: use frequency arrays, maps, and sets; avoid repeated full scans.

### C. Grid / Geometry / Coordinates（网格 / 几何 / 坐标）

- Representative problems: Square Pasture, Blocked Billboard, Team Tic Tac Toe, Triangles, Stamp Grid, Reflection, Farmer John's Cheese Block.
- Exam focus（考试要点）: draw coordinates, standardize indexing, and distinguish grid cells from grid points.

### D. Greedy / Sorting / Ordering（贪心 / 排序 / 顺序）

- Representative problems: Lifeguards, Sleepy Cow Sorting, Cow College, Feeding the Cows, Leaders, Purchasing Milk.
- Exam focus（考试要点）: sort first, then reason about adjacent items, prefixes, suffixes, or safe local choices.

### E. Complete Search（枚举 / 暴力）

- Representative problems: Back and Forth, Livestock Lineup, Non-Transitive Dice, Reverse Engineering, Modern Art.
- Exam focus（考试要点）: constraints decide the solution; a clean brute force is often intended.

## 3. Ten-Year Bronze Problem Table（近十年真题总表）

### 2025-2026 Season

| Contest | P1 | Tags | P2 | Tags | P3 | Tags |
|---|---|---|---|---|---|---|
| First | Chip Exchange | MATH, ADHOC, GREEDY | COW Splits | STR, ADHOC, CONSTRUCTIVE | Photoshoot | GRID, SIM, PREFIX |
| Second | It's Mooin' Time IV | STR, COUNT, ADHOC | Moo Hunt | STR, SEARCH, ADHOC | Purchasing Milk | GREEDY, SORT |
| Third | Make All Distinct | COUNT, SET, ADHOC | Strange Function | MATH, ADHOC | Swap to Win | GREEDY, SORT, ADHOC |

### 2024-2025 Season

| Contest | P1 | Tags | P2 | Tags | P3 | Tags |
|---|---|---|---|---|---|---|
| December | Roundabout Rounding | MATH, ADHOC | Farmer John's Cheese Block | GRID, COUNT, UPDATE | It's Mooin' Time | STR, COUNT |
| January | Astral Superposition | GRID, SIM, ADHOC | It's Mooin' Time II | STR, COUNT | Cow Checkups | COUNT, PREFIX |
| February | Reflection | GRID, SYMMETRY, UPDATE | Making Mexes | COUNT, MATH | Printing Sequences | ADHOC, CONSTRUCTIVE |
| US Open | Hoof Paper Scissors Minus One | COUNT, PREFIX | More Cow Photos | GREEDY, ADHOC | It's Mooin' Time III | STR, COUNT, ADHOC |

### 2023-2024 Season

| Contest | P1 | Tags | P2 | Tags | P3 | Tags |
|---|---|---|---|---|---|---|
| December | Candy Cane Feast | SIM, ADHOC | Cowntact Tracing 2 | STR, COUNT, ADHOC | Farmer John Actually Farms | MATH, ADHOC |
| January | Majority Opinion | COUNT, STR, ADHOC | Cannon Ball | SIM | Balancing Bacteria | PREFIX, GREEDY, MATH |
| February | Palindrome Game | STR, GAME, ADHOC | Milk Exchange | SIM, MATH | Maximizing Productivity | SORT, GREEDY |
| US Open | Logical Moos | STR, LOGIC, PREFIX | Walking Along a Fence | GRID, PATH, PREFIX | Farmer John's Favorite Permutation | SORT, ADHOC |

### 2022-2023 Season

| Contest | P1 | Tags | P2 | Tags | P3 | Tags |
|---|---|---|---|---|---|---|
| December | Cow College | SORT, GREEDY | Feeding the Cows | GREEDY, STR | Reverse Engineering | SEARCH, LOGIC |
| January | Leaders | GREEDY, ADHOC | Air Cownditioning II | SEARCH, SIM | Moo Operations | STR, ADHOC |
| February | Hungry Cow | SIM, MATH | Stamp Grid | GRID, SEARCH | Watching Mooloo | GREEDY, MATH |
| US Open | FEB | STR, COUNT, ADHOC | Moo Language | STR, PARSING | Rotate and Shift | SIM, MATH |

### 2021-2022 Season

| Contest | P1 | Tags | P2 | Tags | P3 | Tags |
|---|---|---|---|---|---|---|
| December | Lonely Photo | STR, COUNT, PREFIX | Air Cownditioning | GREEDY, PREFIX | Walking Home | GRID, SEARCH |
| January | Herdle | STR, COUNT | Non-Transitive Dice | SEARCH, COUNT | Drought | GREEDY, MATH |
| February | Sleeping in Class | MATH, SEARCH | Photoshoot 2 | SORT, ADHOC | Blocks | STR, COUNT |
| US Open | Photoshoot | GREEDY, ADHOC | Counting Liars | SORT, COUNT | Alchemy | SIM, GRAPH |

### 2020-2021 Season

| Contest | P1 | Tags | P2 | Tags | P3 | Tags |
|---|---|---|---|---|---|---|
| December | Do You Know Your ABCs? | SEARCH, MATH | Daisy Chains | SEARCH, COUNT | Stuck in a Rut | SIM, GEOMETRY |
| January | Uddered but not Herd | STR, SIM | Even More Odd Photos | COUNT, GREEDY | Just Stalling | SORT, GREEDY |
| February | Year of the Cow | SORT, MATH | Comfortable Cows | GRID, SIM | Clockwise Fence | GEOMETRY, STR |
| US Open | Acowdemia I | GREEDY, SORT | Acowdemia II | GRAPH, COUNT | Acowdemia III | GRID, COUNT |

### 2019-2020 Season

| Contest | P1 | Tags | P2 | Tags | P3 | Tags |
|---|---|---|---|---|---|---|
| December | Cow Gymnastics | COUNT, SEARCH | Where Am I? | STR, SEARCH | Livestock Lineup | SEARCH, SORT |
| January | Word Processor | SIM, STR | Photoshoot | ADHOC, MATH | Race | MATH, SIM |
| February | Triangles | GEOMETRY, SEARCH | Mad Scientist | STR, SIM | Swapity Swap | SIM, PERMUTATION |
| US Open | Social Distancing I | GREEDY, STR | Social Distancing II | SORT, SIM | Cowntact Tracing | SEARCH, SIM |

### 2018-2019 Season

| Contest | P1 | Tags | P2 | Tags | P3 | Tags |
|---|---|---|---|---|---|---|
| December | Mixing Milk | SIM | The Bucket List | PREFIX, SIM | Back and Forth | SEARCH, SET |
| January | Shell Game | SIM | Sleepy Cow Sorting | SORT, ADHOC | Guess the Animal | COUNT, SET |
| February | Sleepy Cow Herding | SORT, ADHOC | The Great Revegetation | GRAPH, GREEDY | Measuring Traffic | SIM, INTERVAL |
| US Open | Bucket Brigade | GRID, GEOMETRY | Milk Factory | GRAPH | Cow Evolution | SET, SEARCH |

### 2017-2018 Season

| Contest | P1 | Tags | P2 | Tags | P3 | Tags |
|---|---|---|---|---|---|---|
| December | Blocked Billboard | GEOMETRY | The Bovine Shuffle | SIM, ARRAY | Milk Measurement | SIM, SORT |
| January | Blocked Billboard II | GEOMETRY | Lifeguards | SORT, INTERVAL | Out of Place | SORT, ADHOC |
| February | Teleportation | MATH, ADHOC | Hoofball | SORT, SIM | Taming the Herd | ARRAY, ADHOC |
| US Open | Team Tic Tac Toe | GRID, COUNT | Milking Order | SIM, ORDERING | Family Tree | GRAPH, SEARCH |

### 2016-2017 Season

| Contest | P1 | Tags | P2 | Tags | P3 | Tags |
|---|---|---|---|---|---|---|
| December | Square Pasture | GEOMETRY | Block Game | STR, COUNT | The Cow-Signal | GRID, SIM |
| January | Don't Be Last! | SORT, COUNT | Hoof, Paper, Scissors | COUNT, ADHOC | Cow Tipping | GRID, SIM |
| February | Why Did the Cow Cross the Road | COUNT, SIM | Why Did the Cow Cross the Road II | STR, COUNT | Why Did the Cow Cross the Road III | GRID, GRAPH |
| US Open | The Lost Cow | SIM, MATH | Bovine Genomics | STR, COUNT | Modern Art | GRID, SEARCH |

## 4. Reverse Index by Skill（按知识点反向索引）

### Simulation / Implementation（模拟 / 实现）

- 2025-2026 First P3: Photoshoot
- 2024-2025 January P1: Astral Superposition
- 2023-2024 December P1: Candy Cane Feast
- 2023-2024 January P2: Cannon Ball
- 2023-2024 February P2: Milk Exchange
- 2022-2023 January P2: Air Cownditioning II
- 2022-2023 February P1: Hungry Cow
- 2022-2023 US Open P3: Rotate and Shift
- 2021-2022 US Open P3: Alchemy
- 2020-2021 December P3: Stuck in a Rut
- 2020-2021 January P1: Uddered but not Herd
- 2020-2021 February P2: Comfortable Cows
- 2019-2020 January P1: Word Processor
- 2019-2020 January P3: Race
- 2019-2020 February P2: Mad Scientist
- 2019-2020 February P3: Swapity Swap
- 2019-2020 US Open P2: Social Distancing II
- 2019-2020 US Open P3: Cowntact Tracing
- 2018-2019 December P1: Mixing Milk
- 2018-2019 December P2: The Bucket List
- 2018-2019 January P1: Shell Game
- 2018-2019 February P3: Measuring Traffic
- 2017-2018 December P2: The Bovine Shuffle
- 2017-2018 December P3: Milk Measurement
- 2017-2018 February P2: Hoofball
- 2017-2018 US Open P2: Milking Order
- 2016-2017 December P3: The Cow-Signal
- 2016-2017 January P3: Cow Tipping
- 2016-2017 February P1: Why Did the Cow Cross the Road
- 2016-2017 US Open P1: The Lost Cow

### Ad Hoc / Casework（分类讨论）

- 2025-2026 First P1: Chip Exchange
- 2025-2026 First P2: COW Splits
- 2025-2026 Second P1: It's Mooin' Time IV
- 2025-2026 Second P2: Moo Hunt
- 2025-2026 Third P1: Make All Distinct
- 2025-2026 Third P2: Strange Function
- 2025-2026 Third P3: Swap to Win
- 2024-2025 December P1: Roundabout Rounding
- 2024-2025 January P1: Astral Superposition
- 2024-2025 February P3: Printing Sequences
- 2024-2025 US Open P2: More Cow Photos
- 2024-2025 US Open P3: It's Mooin' Time III
- 2023-2024 December P1: Candy Cane Feast
- 2023-2024 December P2: Cowntact Tracing 2
- 2023-2024 December P3: Farmer John Actually Farms
- 2023-2024 January P1: Majority Opinion
- 2023-2024 February P1: Palindrome Game
- 2023-2024 US Open P3: Farmer John's Favorite Permutation
- 2022-2023 January P1: Leaders
- 2022-2023 January P3: Moo Operations
- 2022-2023 US Open P1: FEB
- 2021-2022 February P2: Photoshoot 2
- 2021-2022 US Open P1: Photoshoot
- 2019-2020 January P2: Photoshoot
- 2018-2019 January P2: Sleepy Cow Sorting
- 2018-2019 February P1: Sleepy Cow Herding
- 2017-2018 January P3: Out of Place
- 2017-2018 February P1: Teleportation
- 2017-2018 February P3: Taming the Herd
- 2016-2017 January P2: Hoof, Paper, Scissors

### Greedy（贪心）

- 2025-2026 First P1: Chip Exchange
- 2025-2026 Second P3: Purchasing Milk
- 2025-2026 Third P3: Swap to Win
- 2024-2025 US Open P2: More Cow Photos
- 2023-2024 January P3: Balancing Bacteria
- 2023-2024 February P3: Maximizing Productivity
- 2022-2023 December P1: Cow College
- 2022-2023 December P2: Feeding the Cows
- 2022-2023 January P1: Leaders
- 2022-2023 February P3: Watching Mooloo
- 2021-2022 December P2: Air Cownditioning
- 2021-2022 January P3: Drought
- 2021-2022 US Open P1: Photoshoot
- 2020-2021 January P2: Even More Odd Photos
- 2020-2021 January P3: Just Stalling
- 2020-2021 US Open P1: Acowdemia I
- 2019-2020 US Open P1: Social Distancing I
- 2018-2019 February P2: The Great Revegetation

### Complete Search / Brute Force（枚举 / 暴力）

- 2025-2026 Second P2: Moo Hunt
- 2022-2023 December P3: Reverse Engineering
- 2022-2023 January P2: Air Cownditioning II
- 2022-2023 February P2: Stamp Grid
- 2021-2022 December P3: Walking Home
- 2021-2022 January P2: Non-Transitive Dice
- 2021-2022 February P1: Sleeping in Class
- 2020-2021 December P1: Do You Know Your ABCs?
- 2020-2021 December P2: Daisy Chains
- 2019-2020 December P1: Cow Gymnastics
- 2019-2020 December P2: Where Am I?
- 2019-2020 December P3: Livestock Lineup
- 2019-2020 February P1: Triangles
- 2019-2020 US Open P3: Cowntact Tracing
- 2018-2019 December P3: Back and Forth
- 2018-2019 US Open P3: Cow Evolution
- 2017-2018 US Open P3: Family Tree
- 2016-2017 US Open P3: Modern Art

### Sorting / Ordering（排序）

- 2025-2026 Second P3: Purchasing Milk
- 2025-2026 Third P3: Swap to Win
- 2023-2024 February P3: Maximizing Productivity
- 2023-2024 US Open P3: Farmer John's Favorite Permutation
- 2022-2023 December P1: Cow College
- 2021-2022 February P2: Photoshoot 2
- 2021-2022 US Open P2: Counting Liars
- 2020-2021 January P3: Just Stalling
- 2020-2021 February P1: Year of the Cow
- 2020-2021 US Open P1: Acowdemia I
- 2019-2020 December P3: Livestock Lineup
- 2019-2020 US Open P2: Social Distancing II
- 2018-2019 January P2: Sleepy Cow Sorting
- 2018-2019 February P1: Sleepy Cow Herding
- 2017-2018 December P3: Milk Measurement
- 2017-2018 January P2: Lifeguards
- 2017-2018 January P3: Out of Place
- 2017-2018 February P2: Hoofball
- 2016-2017 January P1: Don't Be Last!

### Counting / Frequency（计数 / 频率）

- 2025-2026 Second P1: It's Mooin' Time IV
- 2025-2026 Third P1: Make All Distinct
- 2024-2025 December P2: Farmer John's Cheese Block
- 2024-2025 December P3: It's Mooin' Time
- 2024-2025 January P2: It's Mooin' Time II
- 2024-2025 January P3: Cow Checkups
- 2024-2025 February P2: Making Mexes
- 2024-2025 US Open P1: Hoof Paper Scissors Minus One
- 2024-2025 US Open P3: It's Mooin' Time III
- 2023-2024 December P2: Cowntact Tracing 2
- 2023-2024 January P1: Majority Opinion
- 2022-2023 US Open P1: FEB
- 2021-2022 December P1: Lonely Photo
- 2021-2022 January P1: Herdle
- 2021-2022 January P2: Non-Transitive Dice
- 2021-2022 February P3: Blocks
- 2021-2022 US Open P2: Counting Liars
- 2020-2021 December P2: Daisy Chains
- 2020-2021 January P2: Even More Odd Photos
- 2020-2021 US Open P2: Acowdemia II
- 2020-2021 US Open P3: Acowdemia III
- 2019-2020 December P1: Cow Gymnastics
- 2018-2019 January P3: Guess the Animal
- 2017-2018 US Open P1: Team Tic Tac Toe
- 2016-2017 December P2: Block Game
- 2016-2017 January P1: Don't Be Last!
- 2016-2017 January P2: Hoof, Paper, Scissors
- 2016-2017 February P1: Why Did the Cow Cross the Road
- 2016-2017 February P2: Why Did the Cow Cross the Road II
- 2016-2017 US Open P2: Bovine Genomics

### Prefix / Difference / Incremental Update（前缀 / 差分）

- 2025-2026 First P3: Photoshoot
- 2024-2025 January P3: Cow Checkups
- 2024-2025 US Open P1: Hoof Paper Scissors Minus One
- 2023-2024 January P3: Balancing Bacteria
- 2023-2024 US Open P1: Logical Moos
- 2023-2024 US Open P2: Walking Along a Fence
- 2021-2022 December P1: Lonely Photo
- 2021-2022 December P2: Air Cownditioning
- 2018-2019 December P2: The Bucket List

### Grid / Geometry（网格 / 几何）

- 2025-2026 First P3: Photoshoot
- 2024-2025 December P2: Farmer John's Cheese Block
- 2024-2025 January P1: Astral Superposition
- 2024-2025 February P1: Reflection
- 2023-2024 US Open P2: Walking Along a Fence
- 2022-2023 February P2: Stamp Grid
- 2021-2022 December P3: Walking Home
- 2020-2021 February P2: Comfortable Cows
- 2020-2021 US Open P3: Acowdemia III
- 2018-2019 US Open P1: Bucket Brigade
- 2017-2018 US Open P1: Team Tic Tac Toe
- 2016-2017 December P3: The Cow-Signal
- 2016-2017 January P3: Cow Tipping
- 2016-2017 February P3: Why Did the Cow Cross the Road III
- 2016-2017 US Open P3: Modern Art

### Graph-lite / Connectivity（轻量图论）

- 2021-2022 US Open P3: Alchemy
- 2020-2021 US Open P2: Acowdemia II
- 2018-2019 February P2: The Great Revegetation
- 2018-2019 US Open P2: Milk Factory
- 2017-2018 US Open P3: Family Tree
- 2016-2017 February P3: Why Did the Cow Cross the Road III

### String Processing（字符串）

- 2025-2026 First P2: COW Splits
- 2025-2026 Second P1: It's Mooin' Time IV
- 2025-2026 Second P2: Moo Hunt
- 2024-2025 December P3: It's Mooin' Time
- 2024-2025 January P2: It's Mooin' Time II
- 2024-2025 US Open P3: It's Mooin' Time III
- 2023-2024 December P2: Cowntact Tracing 2
- 2023-2024 January P1: Majority Opinion
- 2023-2024 February P1: Palindrome Game
- 2023-2024 US Open P1: Logical Moos
- 2022-2023 December P2: Feeding the Cows
- 2022-2023 January P3: Moo Operations
- 2022-2023 US Open P1: FEB
- 2022-2023 US Open P2: Moo Language
- 2021-2022 December P1: Lonely Photo
- 2021-2022 January P1: Herdle
- 2021-2022 February P3: Blocks
- 2020-2021 January P1: Uddered but not Herd
- 2020-2021 February P3: Clockwise Fence
- 2019-2020 December P2: Where Am I?
- 2019-2020 January P1: Word Processor
- 2019-2020 February P2: Mad Scientist
- 2019-2020 US Open P1: Social Distancing I
- 2016-2017 December P2: Block Game
- 2016-2017 February P2: Why Did the Cow Cross the Road II
- 2016-2017 US Open P2: Bovine Genomics

### Math / Number Patterns（数学规律）

- 2025-2026 First P1: Chip Exchange
- 2025-2026 Third P2: Strange Function
- 2024-2025 December P1: Roundabout Rounding
- 2024-2025 February P2: Making Mexes
- 2023-2024 December P3: Farmer John Actually Farms
- 2023-2024 January P3: Balancing Bacteria
- 2023-2024 February P2: Milk Exchange
- 2022-2023 February P1: Hungry Cow
- 2022-2023 February P3: Watching Mooloo
- 2022-2023 US Open P3: Rotate and Shift
- 2021-2022 January P3: Drought
- 2021-2022 February P1: Sleeping in Class
- 2020-2021 December P1: Do You Know Your ABCs?
- 2020-2021 February P1: Year of the Cow
- 2019-2020 January P2: Photoshoot
- 2019-2020 January P3: Race
- 2017-2018 February P1: Teleportation
- 2016-2017 US Open P1: The Lost Cow

## 5. Python/C++ Solution Pack（代码对照目录）

A matched Python/C++ scaffold folder has been generated at:

- `usaco_bronze_site/solutions/python/`
- `usaco_bronze_site/solutions/cpp/`
- `usaco_bronze_site/solutions/README.md`

Note（注意）: the files are structured solution scaffolds with approach notes and matched entry points. They are not claimed as fully verified AC submissions for every problem.

Copyright note（版权说明）: this guide does not reproduce full USACO statement text. Use each problem's official statement link/search from the HTML app for the exact story, input/output specification, examples, and constraints.

## 6. Four-Week Exam Plan（四周备考计划）

### Week 1: Reading + Simulation（读题 + 模拟）
- Goal: reliably solve Bronze P1.
- Practice: 2018-2019 through 2021-2022 P1/P2.

### Week 2: Ad Hoc + Counting（分类讨论 + 计数）
- Goal: improve P2 full-solve rate.
- Practice: Guess the Animal, Cow Gymnastics, Herdle, FEB, Majority Opinion, It's Mooin' Time series.

### Week 3: Grid / Geometry / Search（网格 / 几何 / 枚举）
- Goal: handle common P3 shapes.
- Practice: Blocked Billboard, Team Tic Tac Toe, Triangles, Comfortable Cows, Stamp Grid, Reflection.

### Week 4: Recent Full Sets（近年整套限时）
- Goal: adapt to modern Bronze difficulty.
- Recommended sets: 2022 December, 2023 January, 2023 US Open, 2024 December, 2025 January, 2025 February, 2026 First/Second/Third.

## 7. Contest Checklist（考试检查表）

- [ ] Read the full statement, including constraints and output format.
- [ ] Write the target complexity before coding.
- [ ] Hand-check the sample and at least one boundary case.
- [ ] Standardize 0-index or 1-index arrays.
- [ ] Use `long long` in C++ when values may exceed `int`.
- [ ] Clear state across multiple test cases.
- [ ] Avoid full recomputation inside repeated updates unless the constraints allow it.
- [ ] Recheck newline, spaces, and exact output text before submitting.

## 8. Sources（来源）

- USACO official contest result pages and official problem pages.
- USACO Guide Bronze topic map.
- USACO Solutions Bronze index, used as a historical cross-check.