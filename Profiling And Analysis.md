## Profiling and Analysis

## Test Cases

#### Test Case 1
>
> ((((a+b)*(c*d))>((c*a)+f))>((a*e)+(e>f)))
>

#### Test Case 2
>
> a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f>a+b*c*d>c*a+f>
> a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f>a+b*c*d>c*a+f>a*e+e>f+a
>

#### Test Case 3
>
> a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f>a+b*c*d>c*a+f>
> a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f>a+b*c*d>c*a+f>a*e+e>f+a>a+b*
> c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f>a+b*c*d>c*a+f>a*e+
> e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f>a+b*c*d>c*a+f>a*e+e>f+a+a+b*c*d>
> c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f>a+b*c*d>c*a+f>a*e+e>f*
> a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f>a+b*c*d>c*a+f>a*e+e>f+a*a+b*c*d>c*a+
> f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f>a+b*c*d>c*a+f>a*e+e>f*a+b*
> c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f*a+b*c*d>c*a+f>a*e+e>f>a+b*c*d>c*a+f>a*e+e>f+a*d>f*a+b
>

## Tools Used

#### Gprof
>
> Gprof is a profiling program which collects and arranges statistics on your programs.
> Basically, it looks into each of your functions and inserts code at the head and tail of each one to collect
> timing information (actually, I don't believe it checks each time the function is run, but rather collects
> statistically significant samples). Then, when you run your program normally (that means with any std
> and file i/o you would normally have), it creates gmon.out, raw data which the gprof program turns
> into profiling statistics. At run-time, timing values are obtained by statistical sampling. Sampling is done
> by probing the target program's program counter at regular intervals using operating system interrupts.
> The resulting data is not exact, rather a statistical approximation. The amount of error is usually more
> than one sampling period. If a value is n times the sampling period, the expected error in the value is the
> square root of n sampling periods. A typical sampling period is 0.01 second (10 milliseconds) or 0.001
> second (1 ms) or in other words 100 or 1000 samples per second of CPU running time.
>

#### Callgrind
>
> Callgrind is a Valgrind tool for profiling programs. The collected data consists of the
> number of instructions executed on a run, their relationship to source lines, and call relationship among
> functions together with call counts. It uses the processor emulation of Valgrind to run the executable,
> and catches all memory accesses, which are used to drive a cache simulator. The program does not need
> to be recompiled, it can use shared libraries and plugins, and the profile measurement doesn't influence
> the memory access behaviour. The trace includes the number of instruction/data memory accesses and
> 1st/2nd level cache misses, and relates it to source lines and functions of the run program. A
> disadvantage is the slowdown involved in the processor emulation, around 50 times slower. For
> graphical visualization of the data that is collected by Callgrind, KCachegrind application is used.
> Callgrind includes functions that are native to C/C++ in its analysis. If one of them appears in the
> highest positions of the left panel, it may be the case to try to use a different function or data structure
> that performs a similar task in a more efficient way. Most of the time, however, our functions are the
> ones in most of the top positions in the list.
>

#### Memcheck
>
> Memcheck tracks all memory reads, writes, allocations, and deallocations in a C or
> C++ program. The tool can detect many different memory errors. For instance, it detects reads or writes
> before or after allocated memory blocks. It warns about the use of (partially) undefined values in
> conditional code or passing such values to system calls. It will also notify you about bad or double
> deallocation of memory blocks. A memory leak occurs in C++ when you allocate memory dynamically
> and never give it back. Memcheck can detect this and submit a report back to us. This helps us optimise
> memory usage of a code. For a small, short-lived program that runs and immediately exits, leaks are
> quite harmless, but for a project of larger size and/or longevity, a repeated small leak can eventually add
> up. Memcheck reports summaries about leaked and dubious blocks. For each such block, it will also tell
> you where the block was allocated. This should help you figure out why the pointer to it has been lost.
> In general, you should attempt to ensure your programs do not have any leaked or dubious blocks at
> exit. The precise area of memory in which Memcheck searches for pointers is: all naturally-aligned 4-
> byte words for which all A bits indicate addressibility and all V bits indicated that the stored value is
> actually valid.
>

#### Massif
>
> Massif is a heap profiler. It measures how much heap memory your program uses. This
> includes both the useful space, and the extra bytes allocated for book-keeping and alignment purposes. It
> can also measure the size of your program's stack(s), although it does not do so by default. Also, there
> are certain space leaks that aren't detected by traditional leak-checkers, such as Memcheck's. That's
> because the memory isn't ever actually lost -- a pointer remains to it -- but it's not in use. Programs that
> have leaks like this can unnecessarily increase the amount of memory they are using over time. Massif
> can help identify these leaks. Importantly, Massif tells you not only how much heap memory your
> program is using, it also gives very detailed information that indicates which parts of your program are
> responsible for allocating the heap memory. Heap profiler such as Massif is useful to help you reduce
> the amount of memory your program uses.
>

## Commands Used (Ubuntu Terminal)

#### Gprof:

```bash
    1. g++ -pg Functions.cpp
    2. ./a.out
    3. gprof a.out
```

#### Callgrind:

```bash
    1. valgrind --tool=callgrind ./a.out
    2. callgrind_annotate callgrind.out.%p
    3. kcachegrind callgrind.out.%p
```

#### Memcheck:

```bash
    1. valgrind --tool=memcheck –leak-check=yes -s ./a.out
    2. valgrind --tool=memcheck –xtree-leak=yes ./a.out
    3. callgrind_annotate xtleak.kcg.%p
```

#### Massif:

```bash
    1. valgrind --tool=massif ./a.out
    2. ms_print massif.out.%p
    3. massif-visualizer massif.out.%p
```

## What We Understood From Different Tools

#### Gprof:

<img src = "/Test/TestCase2/gprof/gprof4.png" alt = "gprof-img" height = "800px" width = "1000px">
<img src = "/Test/TestCase2/gprof/gprof5.png" alt = "gprof-img" height = "800px" width = "1000px">

> The call graph shows how much time was spent in each function and its children. From
> this information, you can find functions that, while they themselves may not have used
> much time, called other functions that did use unusual amounts of time. In each entry, the
> primary line is the one that starts with an index number in square brackets. The end of
> this line says which function the entry is for. The preceding lines in the entry describe the
> callers of this function and the following lines describe its . The entries are sorted by time
> spent in the function and its subroutines.

<img src = "/Test/TestCase2/gprof/gprof3.png" alt = "gprof-img" height = "800px" width = "1000px">

> The flat profile shows the total amount of time your program spent executing each
> function. The functions are sorted by first by decreasing run-time spent in them, then by
> decreasing number of calls, then alphabetically by name. The
> functions 'mcount' and 'profil' are part of the profiling aparatus and appear in every flat
> profile; their time gives a measure of the amount of overhead due to profiling. Just before
> the column headers, a statement appears indicating how much time each sample counted
> as. This sampling period estimates the margin of error in each of the time figures. A time
> figure that is not much larger than this is not reliable.

#### Callgrind:

<img src = "/Test/TestCase2/callgrind/cg3.png" alt = "gprof-img" height = "800px" width = "1000px">
<img src = "/Test/TestCase2/callgrind/callgraph.jpg" alt = "gprof-img" height = "800px" width = "1000px">
<img src = "/Test/TestCase2/callgrind/dotgraph.png" alt = "gprof-img" height = "800px" width = "1000px">

> The percentages in call graphs always show the time spent in some given function while
> the selected function was active, ie. the time both functions could be found on the call
> stack during runtime of the program. This works both in callee direction and caller
> direction. This graph shows us the direction of function calls with focus on “parent”
> functions calling other sub functions. According to test cases it also shows us how many
> times a function calls the other function and how much time they both were running
> together. The call graph view shows a graph built up around the currently selected
> function, which is the node centered on the grey-blended pyramid in the background.
> Each node represents a function, and each edge represents calls. Cost shown per function
> is the cost spent while that function and the selected function are running. Suppose a
> function C called both from A and B; in the call-graph of A, cost of node C only gives
> the cost when called from A, not any cost while called from B. For cycles, blue call
> arrows indicate that this is an artificial call added for correct drawing which actually
> never happened.

#### Memcheck:

<img src = "/Test/TestCase3/memcheck/mmc2.png" alt = "gprof-img" height = "800px" width = "1000px">
<img src = "/Test/TestCase3/memcheck/mmc1.png" alt = "gprof-img" height = "800px" width = "1000px">

> Since our program has memory leaks, such an output is coming. Our ultimate goal is to
> optimise our program in such a way that the output becomes 0 bytes in 0 blocks. Blocks
> of statically allocated memory, those available in the stack of the process, will be
> available as long as the program runs, but only in the specific execution context of each
> moment. Anyway, even if internally Valgrind distinguishes 9 different types of memory
> leaks, the generated output report will only include 4 main categories:
>      - Still Reachable: Covers cases 1 and 2 (for the BBB blocks)
>      - Directly Lost: Covers case 3 (for the BBB blocks)
>      - Indirectly Lost: Covers cases 4 and 9 (for the BBB blocks)
>      - Possibly Lost: Covers cases 5, 6, 7 and 8 (for the BBB blocks)<br>
>
> Directly and Indirectly Lost leaks are also referred as Definitely Lost leaks. So According
> to the following cases we can analyse what parts of our codes are losing memory and
> thus optimise accordingly for a smoother running code.<br>
> Resources: https://aleksander.es/data/valgrind-memcheck.pdf

<img src = "/Test/TestCase3/memcheck/xtleak.png" alt = "gprof-img" height = "400px" width = "800px">
<img src = "/Test/TestCase3/memcheck/mmc.png" alt = "gprof-img" height = "400px" width = "800px">

> The increase or decrease for all events above will also be output in the file to provide the
> delta (increase or decrease) between 2 successive leak searches. For example, iRB is the
> increase of the RB event, dPBk is the decrease of PBk event. The values for the increase
> and decrease events will be zero for the first leak search done.

#### Massif:

<img src = "/Test/TestCase3/massif/heapgraph.jpg" alt = "gprof-img" height = "800px" width = "1000px">
<img src = "/Test/TestCase2/massif/msf5.png" alt = "gprof-img" height = "800px" width = "1000px">
<img src = "/Test/TestCase2/massif/msf4.png" alt = "gprof-img" height = "800px" width = "1000px">
<img src = "/Test/TestCase2/massif/heapgraph.jpg" alt = "gprof-img" height = "800px" width = "1000px">

> First part of ms_print's output contains a preamble which just states how the program,
> Massif and ms_print were each invoked. The next part is the graph that shows how
> memory consumption occurred as the program executed. By default, Massif uses
> "instructions executed" as the unit of time. For very short-run programs such as the
> example, most of the executed instructions involve the loading and dynamic linking of
> the program. The execution of main (and thus the heap allocations) only occur at the very
> end. For a short-running program like this, we can use the --time-unit=B option to
> specify that we want the time unit to instead be the number of bytes allocated/deallocated
> on the heap and stack(s). The graph is followed by the detailed information for each
> snapshot. The final detailed snapshot shows how the heap looked at termination. The
> 00.00% entry represents the code locations for which memory was allocated and then
> freed

> All resources including profiling tools output files and the screenshots of their
> running are added as the part of the zip file uploaded for submission