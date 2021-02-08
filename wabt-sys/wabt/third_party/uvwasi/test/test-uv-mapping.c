#include <assert.h>
#include <stdlib.h>
#include "../src/uv_mapping.h"

#define CHECK_ERR(err) assert(uvwasi__translate_uv_error(UV_ ## err ) ==      \
                              UVWASI_ ## err)
#ifndef _WIN32
# define CHECK_SIG(sig) assert(uvwasi__translate_to_uv_signal(UVWASI_ ## sig) \
                               == (sig))
#endif /* _WIN32 */

int main(void) {
  /* Verify error code translation. */
  CHECK_ERR(E2BIG);
  CHECK_ERR(EACCES);
  CHECK_ERR(EADDRINUSE);
  CHECK_ERR(EADDRNOTAVAIL);
  CHECK_ERR(EAFNOSUPPORT);
  CHECK_ERR(EAGAIN);
  CHECK_ERR(EALREADY);
  CHECK_ERR(EBADF);
  CHECK_ERR(EBUSY);
  CHECK_ERR(ECANCELED);
  CHECK_ERR(ECONNABORTED);
  CHECK_ERR(ECONNREFUSED);
  CHECK_ERR(ECONNRESET);
  CHECK_ERR(EDESTADDRREQ);
  CHECK_ERR(EEXIST);
  CHECK_ERR(EFAULT);
  CHECK_ERR(EFBIG);
  CHECK_ERR(EHOSTUNREACH);
  CHECK_ERR(EINTR);
  CHECK_ERR(EINVAL);
  CHECK_ERR(EIO);
  CHECK_ERR(EISCONN);
  CHECK_ERR(EISDIR);
  CHECK_ERR(ELOOP);
  CHECK_ERR(EMFILE);
  CHECK_ERR(EMLINK);
  CHECK_ERR(EMSGSIZE);
  CHECK_ERR(ENAMETOOLONG);
  CHECK_ERR(ENETDOWN);
  CHECK_ERR(ENETUNREACH);
  CHECK_ERR(ENFILE);
  CHECK_ERR(ENOBUFS);
  CHECK_ERR(ENODEV);
  CHECK_ERR(ENOENT);
  CHECK_ERR(ENOMEM);
  CHECK_ERR(ENOPROTOOPT);
  CHECK_ERR(ENOSPC);
  CHECK_ERR(ENOSYS);
  CHECK_ERR(ENOTCONN);
  CHECK_ERR(ENOTDIR);
  CHECK_ERR(ENOTEMPTY);
  CHECK_ERR(ENOTSOCK);
  CHECK_ERR(ENOTSUP);
  CHECK_ERR(ENXIO);
  CHECK_ERR(EPERM);
  CHECK_ERR(EPIPE);
  CHECK_ERR(EPROTO);
  CHECK_ERR(EPROTONOSUPPORT);
  CHECK_ERR(EPROTOTYPE);
  CHECK_ERR(ERANGE);
  CHECK_ERR(EROFS);
  CHECK_ERR(ESPIPE);
  CHECK_ERR(ESRCH);
  CHECK_ERR(ETIMEDOUT);
  CHECK_ERR(ETXTBSY);
  CHECK_ERR(EXDEV);
  assert(uvwasi__translate_uv_error(0) == UVWASI_ESUCCESS);
  assert(uvwasi__translate_uv_error(1) == 1);
  assert(uvwasi__translate_uv_error(-99999) == UVWASI_ENOSYS);

  /* Verify signal translation. */
#ifndef _WIN32
  CHECK_SIG(SIGABRT);
  CHECK_SIG(SIGALRM);
  CHECK_SIG(SIGBUS);
  CHECK_SIG(SIGCHLD);
  CHECK_SIG(SIGCONT);
  CHECK_SIG(SIGFPE);
  CHECK_SIG(SIGHUP);
  CHECK_SIG(SIGILL);
  CHECK_SIG(SIGINT);
  CHECK_SIG(SIGKILL);
  CHECK_SIG(SIGPIPE);
  CHECK_SIG(SIGQUIT);
  CHECK_SIG(SIGSEGV);
  CHECK_SIG(SIGSTOP);
  CHECK_SIG(SIGSYS);
  CHECK_SIG(SIGTERM);
  CHECK_SIG(SIGTRAP);
  CHECK_SIG(SIGTSTP);
  CHECK_SIG(SIGTTIN);
  CHECK_SIG(SIGTTOU);
  CHECK_SIG(SIGURG);
  CHECK_SIG(SIGUSR1);
  CHECK_SIG(SIGUSR2);
  CHECK_SIG(SIGVTALRM);
  CHECK_SIG(SIGXCPU);
  CHECK_SIG(SIGXFSZ);
#endif /* _WIN32 */
  assert(uvwasi__translate_to_uv_signal(255) == -1);

  return 0;
}
