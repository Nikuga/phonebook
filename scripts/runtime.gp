reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'
 
plot [:][:0.100]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.06):($2+0.008):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'optimized with new strcuture'  , \
'' using ($0+0.2):($2+0.004):3 with labels title ' ', \
'' using 4:xtic(1) with histogram title 'optimized with new strcuture and hash table'  , \
'' using ($0+0.4):($2+0.0005):4 with labels title ' '
