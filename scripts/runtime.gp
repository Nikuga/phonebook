reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'
 
plot [:][:0.100]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.06):($4+0.009):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'optimized with new structure'  , \
'' using ($0+0.2):($4+0.005):3 with labels title ' ', \
'' using 4:xtic(1) with histogram title 'optimized with new structure and hash table'  , \
'' using ($0+0.4):($4+0.001):4 with labels title ' '
