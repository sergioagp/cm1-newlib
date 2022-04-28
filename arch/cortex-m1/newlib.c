
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#include "platform.h"
#include "uart_driver.h"

// // ----------------------------------------------------------------------------
// void _init(void) {
// // ----------------------------------------------------------------------------

// }

// // ----------------------------------------------------------------------------
// int _close(int file) {
// // ----------------------------------------------------------------------------

// 	return -1;
// }

// ----------------------------------------------------------------------------
int _fstat(int file, struct stat *st) {
// ----------------------------------------------------------------------------

	st->st_mode = S_IFCHR;
	return 0;
}

// // ----------------------------------------------------------------------------
void * _sbrk(int incr) {
// // ----------------------------------------------------------------------------

  static unsigned int *heap = NULL;
	extern int *end;
  unsigned int *prev_heap;

  if (heap == NULL) {
    heap = (unsigned int *)&end;
  }
  prev_heap = heap;
  heap += incr;
  return prev_heap;
}

// // ----------------------------------------------------------------------------
// int _isatty(int file) {
// // ----------------------------------------------------------------------------

// 	return (file == STDIN_FILENO || file == STDOUT_FILENO || file == STDERR_FILENO) ? 1 : 0;

// }

// // ----------------------------------------------------------------------------
// int _lseek(int file, off_t ptr, int dir) {
// // ----------------------------------------------------------------------------

// 	return 0;
// }

// // ----------------------------------------------------------------------------
// int _open(const char* name, int flags, int mode) {
// // ----------------------------------------------------------------------------
//     return 0;
// }

// ----------------------------------------------------------------------------
int _read(int file, char *ptr, size_t len) {
// ----------------------------------------------------------------------------
	// if (isatty(file)) {

	// 	ssize_t count = 0;
	// 	int rxfifo = -1;

	// 	while( count<len && ((rxfifo = USART3_REG(USART_RDR)) >0) ){
	// 		*ptr++ = (char)rxfifo;
	// 		count++;
	// 	}

	// 	return count;
	// }
	// return -1;
}

int _write(int handle, char *data, int size ) 
{
    int count ;

    handle = handle ; // unused

    for( count = 0; count < size; count++) 
    {
        uartlite_putchar(data[count]) ;  // Your low-level output function here.
    }

    return count;
}