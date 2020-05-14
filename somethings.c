
static struct file_system_type testfs_type = {
    .name       = "testfs",
    .mount      = testfs_get_super,
    .kill_sb    = testfs_kill_sb,
    .owner      = THIS_MODULE
};


static int __init test_init(void)
{
        int retval;
        exclude_kobj = kobject_create_and_add("nullfs", fs_kobj);
        if (!exclude_kobj)
                return -ENOMEM;

        retval = sysfs_create_group(exclude_kobj, &attr_group);
        if (retval)
                kobject_put(exclude_kobj);

    register_filesystem(&nullfs_type);
    return 0;
}

static void __exit test_exit(void)
{
    kobject_put(exclude_kobj);
    unregister_filesystem(&testfs_type);
}

module_init(test_init);
module_exit(test_exit);
