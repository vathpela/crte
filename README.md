A C runtime for UEFI
====================

This is a small C runtime and libc subset for EFI binaries.  The goal is
usability.  It is not completeness or conformance.  *HOWEVER*, in places where
it is incompatibly or unexpectedly non-conformant, things should fail to build,
not have errant behavior at runtime.
