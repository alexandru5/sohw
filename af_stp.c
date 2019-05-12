/*
 * SO2 Tema 4
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/net.h>
#include <linux/in.h>
#include <linux/hashmap.h>
#include <net/sock.h>

#include "stp.h"

MODULE_DESCRIPTION("Simple transfer protocol");
MODULE_AUTHOR("Blondutz&Pici");
MODULE_LICENSE("GPL");

DEFINE_HASHTABLE(socket_hash, HASH_LEN);

struct stp_sock {
	struct sock socket;
	struct sockaddr_stp *addr;
	__be16 port;
	__u8 mac_addr[MAC_LEN];
};

struct hash_node {
	struct stp_sock *data;
	struct hlist_node hashmap;
};

static int stp_create(struct net *net, struct socket *sock, int protocol,
						int kern)
{
	return 0;
}

static int stp_release(struct socket *sock)
{
	return 0;
}

static int stp_bind(struct socket *sock, struct sockaddr *sa,
					int addr_len)
{
	return 0;
}

static int stp_connect(struct socket *sock, struct sockaddr *saddr,
					int addr_len, int flags)
{
	return 0;
}

static int stp_sendmsg(struct socket *sock, struct msghdr *msg, size_t len)
{
	return 0;
}

static int stp_recvmsg(struct socket *sock, struct msghdr *msg, size_t len,
						int flags)
{
	return 0;
}

static const struct proto_ops stp_ops = {
	.family = PF_STP,
	.owner = THIS_MODULE,
	.release = stp_release,
	.bind =	stp_bind,
	.connect = stp_connect,
	.socketpair = sock_no_socketpair,
	.accept = sock_no_accept,
	.getname = sock_no_getname,
	.poll =	datagram_poll,
	.ioctl = sock_no_ioctl,
	.listen = sock_no_listen,
	.shutdown =	sock_no_shutdown,
	.setsockopt = sock_no_setsockopt,
	.getsockopt = sock_no_getsockopt,
	.sendmsg = stp_sendmsg,
	.recvmsg = stp_recvmsg,
	.mmap =	sock_no_mmap,
	.sendpage =	sock_no_sendpage,
};

static struct proto stp_proto = {
	.name = STP_PROTO_NAME,
	.owner = THIS_MODULE,
	.obj_size = 
}

static const struct net_proto_family stp_family_ops = {
	.family =	PF_STP,
	.create =	stp_create,
	.owner	=	THIS_MODULE,
};

static int __init stp_init(void)
{
	return 0;
}

static void __exit stp_exit(void)
{

}

module_init(stp_init);
module_exit(stp_exit);
