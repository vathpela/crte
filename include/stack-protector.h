// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * stack-protector.h - support for stack protector using
 *		       "-fstack-protector-strong -mstack-protector-guard=global"
 *		       or "-fstack-protector -mstack-protector-guard=global"
 *		       in an early constructor.
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef STACK_PROTECTOR_H_
#define STACK_PROTECTOR_H_

extern __public void *__stack_chk_guard;
void __public __noreturn __stack_chk_fail(void);

#endif /* !STACK_PROTECTOR_H_ */
// vim:fenc=utf-8:tw=75:noet
