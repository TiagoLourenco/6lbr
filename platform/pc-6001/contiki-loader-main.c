/*
 * Copyright (c) 2007, Takahide Matsutsuka.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 */

/*
 * \file
 * 	This is a main file with loader.
 * \author
 * 	Takahide Matsutsuka <markn@markn.org>
 */

#include "contiki.h"

#include "program-handler.h"
//#include "process-list-dsc.h"
//#include "shell-dsc.h"
//#include "directory-dsc.h"

/*---------------------------------------------------------------------------*/
int
main(void)
{
  /* initialize process manager. */
  process_init();

  /* start services */
  process_start(&ctk_process, NULL);
  process_start(&program_handler_process, NULL);
  process_start(&etimer_process, NULL);

  /* register programs to the program handler */
  /*
  program_handler_add(&directory_dsc, "Directory", 1);
  program_handler_add(&processes_dsc, "Processes", 1);
  program_handler_add(&shell_dsc, "Command shell", 1);
  */
  while(1) {
    process_run();
    etimer_request_poll();
  }
}
